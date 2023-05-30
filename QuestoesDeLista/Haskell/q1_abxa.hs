mypower :: Int -> Int -> Int
mypower x 0 = 1
mypower x y = x * mypower x (y-1)
