import scala.io.StdIn._
import scala.annotation.tailrec

object Main {

  trait Monoid[A]{
    def op(a1: A, a2: A): A
    def zero: A
  }

  type Per = List[Int]
  type Rot = Dice => Dice

  object DiceRoll extends Monoid[Rot]{

    def op(rot1: Rot, rot2: Rot): Rot = (dice: Dice) => rot2(rot1(dice))
    def zero: Rot = (dice: Dice)=>dice

    val north = List(2,6,3,4,1,5).map(_ - 1)
    val east = List(4,2,1,6,5,3).map(_ - 1)
    val ccw = List(1,4,2,5,3,6).map(_ - 1)

    def rot(perm: Per): Rot = (dice: Dice) => Dice(perm.map(dice.pip))

    def axial(f: Rot): List[Rot] = List(zero,f,op(f,f),op(op(f,f),f))

    def enumerateTop(f: Rot = zero, n: Int = 6): List[Rot] = {
      if(n<=0)List[Rot]()
      else if(n%2==0) f :: enumerateTop(op(f,rot(north)),n-1)
      else f :: enumerateTop(op(f,rot(east)),n-1)
    }

    def enumerate: List[Rot] = enumerateTop().flatMap( e => axial(rot(ccw)).map(op(e,_)))
  }

  case class Dice(pip: List[Int]){
    lazy val all: List[Dice] = DiceRoll.enumerate.map(_(Dice(pip)))
    def ===(that: Dice): Boolean = pip.corresponds(that.pip)(_ == _)
    def ==(that: Dice): Boolean = all.exists(_ === that)
  }

  def main(args: Array[String]): Unit = {
    val pip1 = readLine.split(" ").map(_.toInt).toList
    val pip2 = readLine.split(" ").map(_.toInt).toList
    println(if(Dice(pip1) == Dice(pip2)) "Yes" else "No")
  }
}
