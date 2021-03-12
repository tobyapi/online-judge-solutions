main = do
  n <- readLn
  putStrLn $ show n ++ ": " ++ unwords (fmap show $ primeFactor n)

factors :: Int -> [Int]
factors n = [d | d <- [1..n], n `mod` d == 0]

isPrime :: Int -> Bool
isPrime x =
  null [y | y <- [2..floor $ sqrt $ fromIntegral x], x `mod` y == 0]

primeFactor :: Int -> [Int]
primeFactor n
  | isPrime n = [n]
  | otherwise = reverse $ go [] n
  where
    go res 1 = res
    go res n = go (d : res) (n `div` d)
      where d = factors n !! 1
