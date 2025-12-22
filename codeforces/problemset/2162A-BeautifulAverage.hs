import Data.List

main :: IO()
main = interact run

run :: String -> String
run input =
  let nums = map read (words input) :: [Int]
      (t:rest) = nums
  in unlines (map show (solve t rest))

solve :: Int -> [Int] -> [Int]
solve 0 _ = []
solve t (n:xs) =
  let (a, rest) = splitAt n xs
      ps = scanl' (+) 0 a
      ans = maximum [(ps !! (j + 1) - ps !! i) `div` (j - i + 1)| i <- [0 .. n - 1], j <- [i .. n - 1]]
  in ans:solve (t - 1) rest
