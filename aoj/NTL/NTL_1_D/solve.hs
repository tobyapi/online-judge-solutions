import Data.List
import Data.Ratio

main = do
  n <- readLn
  print $ phi n

phi :: Int -> Int
phi 1 = 1
phi n = numerator $ foldl (\acc x -> acc * (1 - (1 % x)))
                      (n % 1) $ nub (primeFactor n)

factors :: Int -> [Int]
factors n = [d | d <- [1..n], n `mod` d == 0]

isPrime :: Int -> Bool
isPrime x = null [y | y <- [2..(sqr x)], x `mod` y == 0]
  where sqr a = floor $ sqrt $ fromIntegral a

primeFactor :: Int -> [Int]
primeFactor n
  | isPrime n = [n]
  | otherwise = reverse $ go [] n
  where
    go res 1 = res
    go res n = go (d : res) (n `div` d)
      where d = factors n !! 1
