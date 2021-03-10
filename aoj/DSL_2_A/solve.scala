object Main {

  trait Monoid[A]{
  	def op(a1: A, a2: A): A
  	def zero: A
  }

  class PersistentSegmentTree[A](val numOfNode: Int, val M: Monoid[A]){

  	sealed trait Tree{ val value: A }
  	case object Empty extends Tree{ val value: A = M.zero }
  	case class Node(value: A, left: Tree, right: Tree) extends Tree
  	object Node {
  		def apply(value: A) = new Node(value, Empty, Empty)
  		def apply(l: Tree, r: Tree) = new Node(M.op(l.value,r.value),l,r)
  	}

  	private val nil: Node = Node(M.zero,Empty,Empty)
  	private[this] var root: Tree = nil

  	private def updateRec(id: Int, x:A, l: Int = 0, r: Int = numOfNode, t: Tree = root): Tree = {
  		val m = (l + r)/2
  		def branch(now: Node): Node = {
  			if(r-l<=1)Node(x)
  			else if(id < m)Node(updateRec(id,x,l,m, now.left), now.right)
  			else Node(now.left,updateRec(id,x,m,r,now.right))
  		}
  		t match {
  			case now:Node => branch(now)
  			case now:Tree => branch(nil)
  			case _ => nil
  		}
  	}

  	def update(id: Int, x: A):Unit = {
  		root = updateRec(id, x)
  	}

  	def query(a: Int, b: Int, l: Int = 0, r: Int = numOfNode, t: Tree = root): A = {
  		val m = (l + r)/2
  		t match {
  			case now: Node => {
  				if(b<=l || r<=a)M.zero
  				else if(a<=l && r<=b)now.value
  				else M.op(query(a,b,l,m,now.left),query(a,b,m,r,now.right))
  			}
  			case _ => M.zero
  		}
  	}
  }

  def main(args: Array[String]): Unit = {
  	val line = scala.io.StdIn.readLine.split(" ").map(_.toInt)
  	val n = line(0)
  	val q = line(1)
  	val m = new Monoid[Int]{
  		def op(a1: Int, a2: Int): Int = a1 min a2
  		def zero: Int = Int.MaxValue
  	}

  	val segtree = new PersistentSegmentTree[Int](n,m)

  	for(i <- 1 to q){
  		val input = scala.io.StdIn.readLine.split(" ").map(_.toInt)
  		val x = input(1)
  		val y = input(2)
  		if(input(0)==0)segtree.update(x,y)
  		else println(segtree.query(x,y+1))
  	}
  }
}
