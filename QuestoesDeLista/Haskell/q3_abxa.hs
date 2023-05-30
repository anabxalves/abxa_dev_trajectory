mydigits :: String -> String
mydigits [] = ""
mydigits (x:xs)
  | (fromEnum x >= 48) && (fromEnum x <= 57) = x: mydigits xs
  | otherwise = mydigits xs
