file(REMOVE_RECURSE
  "libdature.a"
  "libdature.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/dature.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
