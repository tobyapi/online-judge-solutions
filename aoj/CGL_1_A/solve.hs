import Control.Monad
import Text.Printf

main = do
  line <- fmap (fmap (read :: String -> Double) . words) getLine
  let aa = Point { x = line !! 0, y = line !! 1}
  let bb = Point { x = line !! 2, y = line !! 3}
  let l = Line aa bb
  q <- readLn
  input <- replicateM q getLine
  let xs = fmap (fmap (read :: String -> Double) . words) input
  let result = fmap (\e -> (x $ res l (e !! 0) (e !! 1), y $ res l (e !! 0) (e !! 1))) xs
  mapM_  (\r -> (printf "%.8f %.8f\n" (fst r) (snd r))) result
    where res l x1 y1 = Point{x=x1,y=y1} `project` l

eps :: (Floating a) => a
eps = 1e-7

add :: (Ord a, Floating a) => a -> a -> a
add a b -- = a + b
  | abs (a + b) < eps * (abs a + abs b ) = 0.0
  | otherwise = a + b

data Point a = Point { x :: a, y :: a } deriving (Eq)
data Line a = Line {a :: Point a, b :: Point a}

(^+) :: (Ord a, Floating a) => Point a -> Point a -> Point a
a ^+ b =  Point (add (x a) (x b)) (add (y a) (y b))

(^-) :: (Ord a, Floating a) => Point a -> Point a -> Point a
a ^- b = Point (add (x a) (-x b)) (add (y a) (-y b))

(^*) :: (Floating a) => Point a -> a -> Point a
a ^* d = Point (x a * d) (y a * d)

dot :: (Floating a) => Point a -> Point a -> a
a `dot` b = x a * x b + y a * y b

project :: (Ord a, Floating a) => Point a -> Line a -> Point a
p `project` l = a l ^+ (base ^* t)
  where base = b l ^- a l
        t = ((p ^- a l) `dot` base) / (base `dot` base)
