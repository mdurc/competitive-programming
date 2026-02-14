#set page(
  paper: "us-letter",
  margin: (left: 0.5in, top: 0.5in, bottom: 1cm, right: 0.5in),
)

#set text(size: 10pt)

// #raw(read("dp.cpp"), lang: "cpp")
#let code(file, lang: "cpp") = {
  block(
    width: 100% - 0.5em,
    breakable: true,
    inset: 1em,
    stroke: luma(50%),
    radius: 0.3em,
  )[
    #raw(read(file), lang: lang, theme: "theme.tmTheme")
  ]
}

== Z-Algorithm and KMP
#code("code/strings.cpp")

== Rolling Hash
#code("code/rolling-hash.cpp")
#pagebreak()

== Trie
#code("code/trie.cpp")

== Game Theory
#code("code/game-theory.cpp")

#pagebreak()

== Matrix Operations
#code("code/matrix.cpp")

#pagebreak()

== Graph Algorithms
#code("code/graphs.cpp")
#pagebreak()
#code("code/LCA.cpp")

#pagebreak()

== Dynamic Programming
#code("code/dp.cpp")

== Geometry
#columns(2, gutter: 0pt, [
  #code("code/geometry.cpp")
])

#pagebreak()

== Data Structures
#code("code/DS.cpp")
#code("code/segment-tree.cpp")

#pagebreak()

== Math
#code("code/math.cpp")

== Binary Search
#code("code/binary-search.cpp")
