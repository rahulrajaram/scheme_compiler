definitions = File.readlines("./definition").map(&:strip).shuffle.take(20)
expressions = File.readlines("./expression").map(&:strip).shuffle.take(20)

bodies = []

300.times do
	times = Random.rand(2)
	times_1 = Random.rand(1) + 1
	bodies << "#{definitions.shuffle.take(times).join(" ")} #{expressions.shuffle.take(times_1).join(" ")}"
end
 
100.times do
	bodies.shuffle!
end

puts bodies.take(150).map(&:strip)
