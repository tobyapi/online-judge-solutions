import scala.io.StdIn._
import scala.annotation.tailrec

object Main {

  object Dice{
    private val north = List(2,6,3,4,1,5).map(_ - 1)
    private val east = List(4,2,1,6,5,3).map(_ - 1)
    private val ccw = List(1,4,2,5,3,6).map(_ - 1)

    def vertical(d: Dice): List[Dice] =
      List(d, d.north, d.north.north, d.south)

    def horizontal(d: Dice): List[Dice] =
      List(d, d.east, d.east.east, d.west)

    def turn(d: Dice): List[Dice] = List(d, d.ccw, d.uturn, d.uturn.ccw)

    def enumerateTop(d: Dice, n: Int = 6): List[Dice] = {
      if(n<=0)List[Dice]()
      else d :: enumerateTop(if(n%2==0)d.north else d.east, n-1)
    }

    def enumerate(d: Dice): List[Dice] = enumerateTop(d).flatMap(turn)
  }

  case class Dice(pip: List[Int] = List(1,2,3,4,5,6)) {
    private def north = Dice(Dice.north.map(pip))
    private def east = Dice(Dice.east.map(pip))
    private def south = north.north.north
    private def west = east.east.east
    private def ccw = Dice(Dice.ccw.map(pip))
    private def uturn = ccw.ccw

    def rotate(com: Char):Dice = com match {
      case 'N' => north
      case 'E' => east
      case 'S' => south
      case 'W' => west
      case _ => this
    }
  }

  @tailrec
  def loop(n:Int, all: List[Dice]):Unit = if(n>0){
    val Array(a,b,_*) = readLine.split(" ").map(_.toInt)
    val res = all.filter(d => d.pip(0)==a && d.pip(1)==b)
    println(res(0).pip(2))
    loop(n-1,all)
  }

  def main(args: Array[String]): Unit = {
    val pip = readLine.split(" ").map(_.toInt).toList
    val all: List[Dice] = Dice.enumerate(Dice(pip))
    val Array(n,_*) = readLine.split(" ").map(_.toInt)
    loop(n,all)
  }
}
