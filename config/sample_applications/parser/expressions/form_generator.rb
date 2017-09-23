expressions = File.readlines("./expression").map(&:strip).shuffle.take(20)
definitions = File.readlines("./definition").map(&:strip).shuffle.take(20)

forms = expressions + definitions

puts forms.take(50)
