mypalinDromo :: String -> Bool
myreverse :: String -> String
myreverse [] = ""
myreverse (x:xs) = myreverse xs ++[x]
mypalinDromo [] = True
mypalinDromo (x:xs)
  | myreverse(x:xs) == (x:xs) = True
  | otherwise = False