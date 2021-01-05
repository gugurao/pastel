add_requires("libsdl")

target("console")    
    set_kind("binary")
    add_files("src/**.cc")
    add_packages("libsdl")