object Main {
  def main(args: Array[String]): Unit = {
    val n = readInt
    val list = (for(i <- 1 to n) yield {
      val Array(a,b,_*) = readLine.split(" ")
      (a, b.toInt)
    }).toList
    val res = ((List.fill(13)("S") zip (1 to 13)) ++
    (List.fill(13)("H") zip (1 to 13)) ++
    (List.fill(13)("C") zip (1 to 13)) ++
    (List.fill(13)("D") zip (1 to 13))).filterNot(list.contains)
    for(e <- res)println(e._1+" "+e._2)
  }
}
