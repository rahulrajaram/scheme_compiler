puts File.readlines('./derived_expression').map(&:strip).shuffle.take(50).join("\n")
