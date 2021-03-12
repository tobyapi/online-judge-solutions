main = do
  a <- fmap (map (read :: String -> Int) . words) getLine
  print $ length [x | x <- [(a !! 0)..(a !! 1)], (a !! 2) `mod` x == 0]
