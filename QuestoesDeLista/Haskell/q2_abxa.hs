myelemNum :: Int -> [Int] -> Int
myelemNum n [] = 0
myelemNum n (x:xs) 
  | x == n = 1 + myelemNum n xs
  | otherwise = 0 + myelemNum n xs
  