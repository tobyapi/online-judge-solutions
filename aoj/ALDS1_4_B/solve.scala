import scala.io.StdIn._
import scala.annotation.tailrec
   
object Main {
  @tailrec
  def binarySearch(f: Int => Int, l: Int, r: Int): Int = {
    if(r-l<=1)f(l)
    else if(f((l+r)/2) < 1)binarySearch(f,(l+r)/2,r)
    else binarySearch(f,l,(l+r)/2)
  }
  
  def main(args: Array[String]): Unit = {
    val n = readInt
    val list = readLine.split(" ").map(_.toInt)
   
    val f = (ar: Seq[Int], a: Int) => (x: Int) => ar(x)-a
   
    val q = readInt
    val qlist = readLine.split(" ").map(_.toInt)
    val res = for(e <- qlist)yield binarySearch(f(list,e),0,n)
    println(res.count(_ == 0))
  }
}
