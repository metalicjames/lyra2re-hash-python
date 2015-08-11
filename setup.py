from distutils.core import setup, Extension

lyra2re2_hash_module = Extension('lyra2re2_hash',
                               sources = [
										  'lyra2remodule.c',
										  'lyra2re2module.c',
                                          'Lyra2RE.c',
										  'Sponge.c',
										  'Lyra2.c',
										  'sha3/blake.c',
										  'sha3/groestl.c',
										  'sha3/keccak.c',
										  'sha3/cubehash.c',
										  'sha3/bmw.c',
										  'sha3/skein.c'],
                               include_dirs=['.', './sha3'])

setup (name = 'lyra2re2_hash',
       version = '1.0',
       description = 'Bindings for Lyra2RE2 proof of work used by Vertcoin',
       ext_modules = [lyra2re2_hash_module])

