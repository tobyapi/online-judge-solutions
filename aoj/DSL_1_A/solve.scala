object Main {

  class UnionFindRank(val n: Int) {
    private[this] val par = Array.range(0, n)
    private[this] val rank = Array.fill(n)(1)

    def root(x: Int): Int =
      if(par(x)==x) x
      else {par(x) = root(par(x)); par(x)}

    def same(x: Int, y: Int): Boolean = root(x)==root(y)

    def unite(ax: Int, ay: Int): Unit = {
      val x = root(ax)
      val y = root(ay)
      if(x!=y){
        if(rank(x) < rank(y)) par(x) = y
        else {
          par(y) = x
          if(rank(x) == rank(y))rank(x) = rank(x)+1;
        }
      }
    }
  }

  def main(args: Array[String]): Unit = {

    val Array(n,q,_*) = scala.io.StdIn.readLine.split(" ").map(_.toInt)
    val uf = new UnionFindRank(n)

    for(i <- 1 to q){
      val Array(com,x,y,_*) = scala.io.StdIn.readLine.split(" ").map(_.toInt)
      if(com==0)uf.unite(x,y)
      else println(if(uf.same(x,y)) 1 else 0)
    }

  }

}
