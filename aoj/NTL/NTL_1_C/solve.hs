main = do
  n <- getLine
  a <- fmap (map (read :: String -> Int) . words) getLine
  print $ foldl lcm 1 a
