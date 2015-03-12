##
## Getprocpath Test
##

assert("Getprocpath#hello") do
  t = Getprocpath.new "hello"
  assert_equal("hello", t.hello)
end

assert("Getprocpath#bye") do
  t = Getprocpath.new "hello"
  assert_equal("hello bye", t.bye)
end

assert("Getprocpath.hi") do
  assert_equal("hi!!", Getprocpath.hi)
end
