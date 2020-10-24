typedef struct typeInfo
{
	char* varname;
	enum {primitive, rect_array, jagged_array} tag;
	enum {not_applicable, static_, dynamic} ;  

	// union 
	// {
	// //populate later
	// }typeExp;

}typeInfo;
