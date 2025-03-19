set_project("2022")

set_languages("cxx17")

target("2022")
    set_kind("binary")
    add_includedirs("include")
    add_files("src/main.cpp")
