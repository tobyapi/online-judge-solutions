import scala.io.StdIn.readLine

object Main {
  def main(args: Array[String]): Unit = {
    readLine
    println(readLine.split(" ").map(_.toInt).reverse.mkString(" "))
  }
}
