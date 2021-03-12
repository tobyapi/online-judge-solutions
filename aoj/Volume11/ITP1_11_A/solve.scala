import scala.io.StdIn._

object Main {

  object Dice{
    private val north = List(2,6,3,4,1,5).map(_-1)
    private val east = List(4,2,1,6,5,3).map(_-1)
    private val ccw = List(3,2,6,1,5,4).map(_-1)
  }

  case class Dice(pip: List[Int]) {
    def north = Dice(Dice.north.map(pip))
    def east = Dice(Dice.east.map(pip))
    def south = north.north.north
    def west = east.east.east
  }

  def main(args: Array[String]): Unit = {
    val pip = readLine.split(" ").map(_.toInt).toList
    val commands = readLine

    var dice = Dice(pip)

    for(com <- commands){
      dice = com match {
        case 'N' => dice.north
        case 'E' => dice.east
        case 'S' => dice.south
        case 'W' => dice.west
        case _ => dice
      }
    }
    
    println(dice.pip(0))
  }
}
