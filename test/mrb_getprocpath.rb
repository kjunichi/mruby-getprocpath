##
## Getprocpath Test
##


assert("Getprocpath.get") do
  assert_equal("mrbtest",Getprocpath.get().split("/")[-1])
end
