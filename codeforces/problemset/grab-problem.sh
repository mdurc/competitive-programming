#!/bin/bash

# Sample inputs (contest page or problemset page):
# https://codeforces.com/problemset/problem/2135/A2
# https://codeforces.com/contest/2135/problem/A1

# ./script.sh <codeforces-problem-url>
# ./script.sh update        # refresh problemset data json from codeforces API

data_file="problemsetdata.json"

if [[ "$1" == "update" ]]; then
    curl https://codeforces.com/api/problemset.problems -o $data_file
    if [[ $? -ne 0 ]]; then
        echo "Failed to download problem set."
        exit 1
    fi
    echo "Update complete."
    exit 0
fi

url="$1"
if [[ -z "$url" ]]; then
  echo "Usage: $0 <codeforces-problem-url> or $0 update"
  exit 1
fi

contestId=$(echo $url | grep -oE '/[0-9]+' | tr -d '/')
index=$(echo $url | grep -oE '/[A-Z]+[0-9]*' | tr -d '/')
# api_json="$(curl https://codeforces.com/api/problemset.problems)"
api_json="$(cat $data_file)"

status="$(echo "$api_json" | jq -r '.status')"
if [[ "$status" != "OK" ]]; then
  echo "API error:"
  echo "$api_json" | jq -r '.comment'
  exit 1
fi

problem_json=$(echo "$api_json" | jq --arg idx "$index" --argjson cid "$contestId" '.result | {
    problem: (.problems[] | select(.contestId == $cid and .index == $idx)),
    problemStat: (.problemStatistics[] | select(.contestId == $cid and .index == $idx))
  }'
)
# cat problem-set.json | jq '.result | { problem: (.problems[] | select(.contestId == 2180 and .index == "C")), problemStat: (.problemStatistics[] | select(.contestId == 2180 and .index == "C"))}'

if [[ -z "$problem_json" ]]; then
  echo "Problem ($contestId:$index) was not found"
  exit 1
fi

problem_name=$(echo "$problem_json" | jq -r '.problem.name')
problem_contestId=$(echo "$problem_json" | jq -r '.problem.contestId')
problem_index=$(echo "$problem_json" | jq -r '.problem.index')
problem_type=$(echo "$problem_json" | jq -r '.problem.type')
problem_rating=$(echo "$problem_json" | jq -r '.problem.rating')
problem_tags=$(echo "$problem_json" | jq -r '.problem.tags | join(", ")')
solved_count=$(echo "$problem_json" | jq -r '.problemStat.solvedCount')

echo "Problem: $problem_contestId$problem_index - $problem_name"
echo "Rating: $problem_rating"
echo "Solved: $solved_count"
echo "Tags: $problem_tags"

file=$(echo "$problem_contestId$problem_index-$problem_name.cpp" | tr -d ' ')
touch "$file"
nvim "$file"
