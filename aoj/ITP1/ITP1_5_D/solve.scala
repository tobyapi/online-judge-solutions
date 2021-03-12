
object Main{
  def main(args: Array[String]): Unit = {
    println(" "+(3 to scala.io.StdIn.readInt).filter(e => e%3 == 0 || e.toString.contains('3')).mkString(" "))
  }
}
