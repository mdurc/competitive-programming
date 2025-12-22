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
solve t (n:xs) = 1:solve (t - 1) xs
