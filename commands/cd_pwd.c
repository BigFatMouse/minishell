#include "minishell.h"

// 1 - взять путь функцией getcwd
// 2 - pwd напечатать
// 3 - cd вызвать функцию chdir меняет текущий каталог, принимает относительный и абсолютный путь
// 4 - записать в env OLDPATH старый путь
// 5 - добавить в env pwd новый путь (абсолютный)??
// 6 - просто cd берется из env HOME
// 7 - обработать ошибки: когда путь не открылся, когда пути не существует (через errno?)

void pwd(t_list *list)
{
	char	path[PATH_MAX];
	getcwd(path, PATH_MAX);
	export("OLDPWD", path, list);
}


int main()
{   
	char path[PATH_MAX];
	printf("%s\n", getcwd(path, PATH_MAX));
	chdir("..");
	printf("%s\n", getcwd(path, PATH_MAX));
	return 0;
}