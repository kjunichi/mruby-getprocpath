# mruby-getprocpath   [![Build Status](https://travis-ci.org/kjunichi/mruby-getprocpath.png?branch=master)](https://travis-ci.org/kjunichi/mruby-getprocpath)
Getprocpath class
## install by mrbgems
- add conf.gem line to `build_config.rb`

```ruby
MRuby::Build.new do |conf|

    # ... (snip) ...

    conf.gem :github => 'kjunichi/mruby-getprocpath'
end
```
## example
```ruby
p Getprocpath.get
#=> "/Users/foo/Downloads/mruby/bin/mirb"

```

## License
under the MIT License:
- see LICENSE file
