object Main {

  def gcd(a: Long, b: Long): Long = if(b!=0) gcd(b,a%b) else a

  def lcm(a: Long, b: Long): Long = a * b / gcd(a,b)

  def loop(s: String):Unit = if(s != null){
    val Array(a,b,_*) = s.split(" ").map(_.toLong)
    println(gcd(a,b)+" "+lcm(a,b))
    loop(scala.io.StdIn.readLine)
  }

  def main(args: Array[String]): Unit = {
    loop(scala.io.StdIn.readLine)
  }
}
