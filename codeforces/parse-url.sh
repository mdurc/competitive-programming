#!/bin/bash

# Sample inputs (contest page or problemset page):
# https://codeforces.com/problemset/problem/2135/A2
# https://codeforces.com/contest/2135/problem/A1

data_file="/Users/mdurcan/personal/competitive-programming/codeforces/data.json"

usage() {
  echo "Usage:"
  echo "$0 update"                    # refresh problemset data json from codeforces API
  echo "$0 <codeforces-problem-url>"  # contest or problemset link
  echo "$0 random <min-rating> <max-rating>"
  exit 1
}
check_api_error() {
  local api_json="$1"
  local status
  status="$(echo "$api_json" | jq -r '.status')"
  if [[ "$status" != "OK" ]]; then
    echo "API error:"
    echo "$api_json" | jq -r '.comment'
    exit 1
  fi
}
extract_problem_data() {
    local problem_json="$1"
    if [[ "$problem_json" == "null" || -z "$problem_json" ]]; then
      echo "No problem data found"
      exit 1
    fi
    problem_name=$(echo "$problem_json" | jq -r '.problem.name')
    problem_contestId=$(echo "$problem_json" | jq -r '.problem.contestId')
    problem_index=$(echo "$problem_json" | jq -r '.problem.index')
    problem_type=$(echo "$problem_json" | jq -r '.problem.type')
    problem_rating=$(echo "$problem_json" | jq -r '.problem.rating')
    problem_tags=$(echo "$problem_json" | jq -r '.problem.tags | join(", ")')
    problem_solved_count=$(echo "$problem_json" | jq -r '.problemStat.solvedCount')
}
print_problem_data() {
  echo "Problem: $problem_contestId$problem_index - $problem_name"
  echo "Rating: $problem_rating"
  echo "Solved: $problem_solved_count"
  # echo "Tags: $problem_tags"
  echo "https://codeforces.com/problemset/problem/$problem_contestId/$problem_index"
}
enter_problem() {
  file=$(echo "$problem_contestId$problem_index-$problem_name.cpp" | tr -cd '[:alnum:]._-' )
  touch "$file"
  nvim "$file"
}

############################################################

if [[ "$1" == "update" ]]; then
  curl https://codeforces.com/api/problemset.problems -o $data_file
  if [[ $? -ne 0 ]]; then
    echo "Failed to download problem set."
    exit 1
  fi
  echo "Update complete."
elif [[ "$1" == "random" ]]; then
  min_rating="$2"
  max_rating="$3"

  if [[ -z "$min_rating" || -z "$max_rating" ]]; then
    usage
  fi

  api_json="$(cat "$data_file")"
  check_api_error "$api_json"

  filtered=$(echo "$api_json" | jq --argjson min "$min_rating" --argjson max "$max_rating" '
  .result.problems | map(select(.rating != null and .rating >= $min and .rating <= $max))
  ')
  length=$(echo "$filtered" | jq 'length')
  random_index=$((RANDOM % length))
  problem_json=$(echo "$api_json" | jq --argjson min "$min_rating" --argjson max "$max_rating" --argjson idx "$random_index" '
  .result |
    (.problems | map(select(.rating != null and .rating >= $min and .rating <= $max)).[$idx]) as $p |
    select($p) |
    {
      problem: $p,
      problemStat: (.problemStatistics[] | select(.contestId == $p.contestId and .index == $p.index))
    }')

  extract_problem_data "$problem_json"
  print_problem_data
  enter_problem
else
  url="$1"
  if [[ -z "$url" ]]; then
    usage
  fi

  contestId=$(echo "$url" | grep -oE '/[0-9]+' | tr -d '/')
  index=$(echo "$url" | grep -oE '/[A-Z]+[0-9]*' | tr -d '/')

  # api_json="$(curl https://codeforces.com/api/problemset.problems)"
  api_json="$(cat "$data_file")"
  check_api_error "$api_json"

  problem_json=$(echo "$api_json" | jq --arg idx "$index" --argjson cid "$contestId" '.result | {
    problem: (.problems[] | select(.contestId == $cid and .index == $idx)),
    problemStat: (.problemStatistics[] | select(.contestId == $cid and .index == $idx))
  }')
  # cat problem-set.json | jq '.result | { problem: (.problems[] | select(.contestId == 2180 and .index == "C")), problemStat: (.problemStatistics[] | select(.contestId == 2180 and .index == "C"))}'

  extract_problem_data "$problem_json"
  print_problem_data
  enter_problem
fi
