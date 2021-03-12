import scala.io.StdIn._
import scala.annotation.tailrec
import scala.collection._

object Main {

  def makeSoE_PrimesTo(top: Int) = {
    val topNdx = (top - 3) / 2 + 1
    val (cmpsts, sqrtLmtNdx) = (new Array[Int]((topNdx >>> 5) + 1), (Math.sqrt(top).toInt - 3) / 2)

    @inline def isCmpst(ci: Int): Boolean =
      (cmpsts(ci >>> 5) & (1 << (ci & 31))) != 0

    @inline def setCmpst(ci: Int): Unit =
      cmpsts(ci >>> 5) |= 1 << (ci & 31)

    @tailrec def forCndNdxsFrom(cndNdx: Int): Unit =
      if(cndNdx <= sqrtLmtNdx){
        if(!isCmpst(cndNdx)){
          val p = cndNdx + cndNdx + 3

          @tailrec def cullPrmCmpstsFrom(cmpstNdx: Int): Unit =
          if(cmpstNdx <= topNdx){
            setCmpst(cmpstNdx)
            cullPrmCmpstsFrom(cmpstNdx + p)
          }
          cullPrmCmpstsFrom((p * p - 3) >>> 1)
        }
        forCndNdxsFrom(cndNdx + 1)
      }
      forCndNdxsFrom(0)

    @tailrec def getNxtPrmFrom(cndNdx: Int): Int =
      if ((cndNdx > topNdx) || !isCmpst(cndNdx)) cndNdx + cndNdx + 3
      else getNxtPrmFrom(cndNdx + 1)

    Iterator.single(2) ++ Iterator.iterate(3)(p => getNxtPrmFrom(((p + 2) - 3) >>> 1)).takeWhile(_ <= top)
  }

  @tailrec
  def loop(s: String){
    if(s != null){
       val Array(n,_*) = s.split(" ").map(_.toInt)
       if(n<2) println(0)
       else println(makeSoE_PrimesTo(n).size)
       loop(readLine)
    }
  }

  def main(args: Array[String]): Unit ={
    loop(readLine)
  }
}
