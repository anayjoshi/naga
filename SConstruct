install_path = ARGUMENTS.get('install_path', '/usr/local/bin')
print install_path
src_files = Split("""src/main.c
                    src/naga.c
                    src/keypress.c
                    src/curses_wrapper.c
                    src/utils.c
                    src/render.c
                    src/engine.c""")

#Program('naga', src_files, LIBS=['pthread', 'ncurses'])
env = Environment()
naga = Program('naga', src_files, LIBS=['pthread', 'ncurses'])
env.Install(install_path, naga)
env.Alias('install', install_path)

Help("""
Type: 'scons program' to build the production program,
      """)
       
