from distutils.core import setup, Extension

lyra2re_hash_module = Extension('lyra2re_hash',
                               sources = ['lyra2remodule.c',
                                          'Lyra2RE.c',
										  'Sponge.c',
										  'Lyra2.c',
										  'sha3/blake.c',
										  'sha3/groestl.c',
										  'sha3/keccak.c',
										  'sha3/skein.c'],
                               include_dirs=['.', './sha3'])

setup (name = 'lyra2re_hash',
       version = '1.0',
       description = 'Bindings for Lyra2RE proof of work used by Vertcoin',
       ext_modules = [lyra2re_hash_module])
