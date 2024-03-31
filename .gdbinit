define pstack
  set var $it = $arg0
  while $it
    print *$it
    set var $it = $it->next
  end
end