{
	'variables': {
		'library%': 'static_library'
	},
	'targets': [ {
		'target_name': 'ropt',
		'type': '<(library)',
		'sources': [
			'ropt.c'
		],
		'direct_dependent_settings': {
			'include_dirs': [ '.' ]
		}
	} ]
}
