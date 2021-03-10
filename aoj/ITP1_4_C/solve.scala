object Main {

  def loop(exp: Array[String]):Unit={
    if(!exp.contains("?")){
      println(exp(1) match {
        case "+" => exp(0).toInt+exp(2).toInt
        case "-" => exp(0).toInt-exp(2).toInt
        case "*" => exp(0).toInt*exp(2).toInt
        case "/" => exp(0).toInt/exp(2).toInt
      })
      loop(readLine.split(" "))
    }
  }

  def main(args: Array[String]): Unit = loop(readLine.split(" "))
}
