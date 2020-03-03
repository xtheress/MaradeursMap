ADD_PRIME_SUMM\n#include <unistd.h>\n\nvoid	ft_putchar(char c)\n{\n	write(1, &c, 1);\n}\n\nvoid	ft_putposnbr(int n)\n{\n	if (n > 9)\n		ft_putposnbr(n / 10);\n	ft_putchar(n %% 10 + \'0\');\n}\n\nint		ft_atoi_nc(char *s)\n{\n	int		r;\n\n	r = 0;\n	while (*s >= \'0\' && *s <= \'9\')\n		r = r * 10 + *s++ - \'0\';\n	return (r);\n}\n\n\nint is_prime(int n)\n{\n	int i;\n\n	i = 2;\n	while (i < n)\n		if (!(n %% i++))\n			return (0);\n	return (1);\n}\n\n\nvoid	add_prime_sum(int n)\n{\n	int	i;\n	int	count;\n\n	count = 0;\n	if (n == 1)\n		count = 1;\n	i = 1;\n	while (++i <= n)\n		if (is_prime(i))\n			count += i;\n	ft_putposnbr(count);\n}\n\nint		main(int ac, char **av)\n{\n	if (ac == 2 && ft_atoi_nc(av[1]) > 0)\n		add_prime_sum(ft_atoi_nc(av[1]));\n	else\n		write(1, \"0\", 1);\n	write(1, \"\\n\", 1);\n	return (1);\n}\n\nEPUR_STR\n#include <unistd.h>\n\nint		ft_strlen(char *s)\n{\n	int i;\n\n	i = 0;\n	while (s[i])\n		i++;\n	return (i);\n}\n\nint		ft_isblank(char c)\n{\n	if (c == \' \' || c == \'\\t\')\n		return (1);\n	if (c >= 9 && c <= 13)\n		return (1);\n	return (0);\n}\n\nvoid	epurstr(char *s)\n{\n	int len = ft_strlen(s);\n\n	while (len && ft_isblank(s[len - 1]))\n		--len;\n	while (len && ft_isblank(*s) && *s++)\n		--len;\n	while (len--)\n	{\n		if (!ft_isblank(*s) || (*(s + 1) && !ft_isblank(*(s + 1))))\n			write(1, s, 1);\n		s++;\n	}\n}\n\nint		main(int ac, char **av)\n{\n	if (ac == 2 && *av[1])\n		epurstr(av[1]);\n	write(1, \"\\n\", 1);\n	return (0);\n}\n\nFT_LIST_SIZE\n#include \"ft_list.h\"\n/*\n#ifndef FT_LIST_H\n# define FT_LIST_H\n\ntypedef struct	s_list\n{\n	struct s_list	*next;\n	void			*data;\n}				t_list;\n\n#endif\n*/\n\nint	ft_list_size(t_list *begin_list)\n{\n	t_list	*list;\n	int		i;\n\n	i = 0;\n	list = begin_list;\n	while (list)\n	{\n		i++;\n		list = list->next;\n	}\n	return (i);\n}\n\nFT_RRANGE\n#include <stdlib.h>\n\nint     *ft_rrange(int start, int end)\n{\n	int	*r;\n	int	len;\n\n	len = (end >= start) ? end - start + 1 : start - end + 1;\n	if (!(r = (int*)malloc(sizeof(int) * len)))\n		return (NULL);\n	 while (len--)\n		 r[len] = (end >= start) ? start++ : start--;\n	return (r);\n}\n\nHIDENP \n#include <unistd.h>\n\nvoid	hidenp(char *s1, char *s2)\n{\n	while (*s2)\n		if (*s1 == *s2++)\n			s1++;\n	(*s1 == \'\\0\') ? write(1, \"1\", 1) : write(1, \"0\", 1);\n}\n\nint	main(int argc, char **argv)\n{\n	if (argc == 3)\n		hidenp(argv[1], argv[2]);\n	write(1, \"\\n\", 1);\n	return (0);\n}\n\nPGCD\n#include <stdio.h>\n#include <stdlib.h>\n\nint		pgcd(unsigned int nb, unsigned int nb2)\n{\n	int i;\n\n	i = nb;\n	while (i > 0)\n	{\n		if (nb %% i == 0 && nb2 %% i == 0)\n			return (i);\n		i--;\n	}\n	return (1);\n}\n\nint	main(int argc, char **argv)\n{\n	if (argc == 3)\n		printf(\"%%d\", pgcd(atoi(argv[1]), atoi(argv[2])));\n	printf(\"\\n\");\n	return (0);\n}\n\nPRINT_HEX \n#include <unistd.h>\n\nint		ft_atoi(char *s)\n{\n	long	r;\n	int		sign;\n\n	while (*s == 32 || (*s >= 9 && *s <= 13))\n		s++;\n	sign = (*s == \'-\') ? -1 : 1;\n	(*s == \'-\' || *s == \'+\') ? s++ : s;\n	r = 0;\n	while (*s >= \'0\' && *s <= \'9\')\n		r = r * 10 + *s++ - \'0\';\n	return ((int)r * sign);\n}\n\nvoid	print_hex(int n)\n{\n	if (n >= 16)\n		print_hex(n / 16);\n	n = n %% 16;\n	n += n < 10 ? \'0\' : \'a\' - 10;\n	write(1, &n, 1);\n}\n\nint		main(int ac, char **av)\n{\n	if (ac == 2)\n		print_hex(ft_atoi(av[1]));\n	write(1, \"\\n\", 1);\n	return (1);\n}\n\nRSTR_CAPITALIZER \n#include <unistd.h>\n\nvoid	ft_putchar(char c)\n{\n	write(1, &c, 1);\n}\n\nvoid	rstr_capitalizer(int argc, char **argv)\n{\n	int i;\n	int j;\n\n	i = 1;\n	j = 0;\n	while (i < argc)\n	{\n		j = 0;\n		while (argv[i][j] != \'\\0\')\n		{\n			if (argv[i][j] >= \'A\' && argv[i][j] <= \'Z\' )\n				argv[i][j] += 32;\n			if (argv[i][j + 1] == \' \' || argv[i][j + 1] == \'\\t\' || argv[i][j + 1] == \'\\0\')\n			{\n				if (argv[i][j] >= \'a\' && argv[i][j] <= \'z\')\n					argv[i][j] -= 32;\n			}\n			ft_putchar(argv[i][j]);\n			j++;\n		}\n		ft_putchar(\'\\n\');\n		i++;\n	}\n}\n\nint		main(int argc, char **argv)\n{\n	if (argc > 1)\n		rstr_capitalizer(argc, argv);\n	else\n		ft_putchar(\'\\n\');\n	return (0);\n}\n\nEXPAND_STR\n#include <unistd.h>\n\nint		ft_isblank(char c)\n{\n	return ((c == \' \' || c == \'\\t\') ? 1 : 0);\n}\n\nvoid	expand_str(char *s)\n{\n	int	i = 0;\n	int	wc = 0;\n\n	while (s[i])\n		if (!ft_isblank(s[i++]) && (!wc || ft_isblank(s[i - 2])))\n			++wc;\n	i = 0;\n	while (s[i])\n	{\n		if (!ft_isblank(s[i++]) && wc--)\n		{\n			write (1, &s[i - 1], 1);\n			while (s[i] && !ft_isblank(s[i]) && write(1, &s[i++], 1));\n			(wc) ? write(1, \"   \", 3) : 0;\n		}\n	}\n}\n\nint		main(int ac, char **av)\n{\n	if (ac == 2)\n		expand_str(av[1]);\n	write(1, \"\\n\", 1);\n}\n\nLCM \nunsigned int    lcm(unsigned int a, unsigned int b)\n{\n    unsigned int    d;\n\n    if (!a || !b)\n        return (0);\n    if (a > b)\n        d = (a / 2) + 1;\n    else\n        d = (b / 2) + 1;\n    while (!((a %% d) == 0 && (b %% d) == 0))\n        d--;\n    return (a * b / d);\n}\n\nTAB_MULT \n#include <unistd.h>\n\nvoid	ft_putchar(char c)\n{\n	write(1, &c, 1);\n}\n\nvoid	ft_putposnbr(int n)\n{\n	if (n > 9)\n		ft_putposnbr(n / 10);\n	ft_putchar(n %% 10 + \'0\');\n}\n\nint		ft_atoi_osefvalid(char *s)\n{\n	int		r;\n\n	r = 0;\n	while (*s >= \'0\' && *s <= \'9\')\n		r = r * 10 + *s++ - \'0\';\n	return (r);\n}\n\nvoid	tab_mult(int n)\n{\n	int i = 1;\n	while (i < 10)\n	{\n		ft_putposnbr(i);\n		write(1,\" x \", 3);\n		ft_putposnbr(n);\n		write(1, \" = \", 3);\n		ft_putposnbr(i++ * n);\n		write(1, \"\\n\", 1);\n	}\n}\n\nint		main(int ac, char **av)\n{\n	if (ac == 2)\n		tab_mult(ft_atoi_osefvalid(av[1]));\n	else\n		write(1, \"\\n\", 1);\n	return (0);\n}\n\nFT_ATOI_BASE \nint isblank(char c)\n{\n	if (c <= 32)\n		return (1);\n	return (0);\n}\n\nint		isvalid(char c, int base)\n{\n	char digits[17] = \"0123456789abcdef\";\n	char digits2[17] = \"0123456789ABCDEF\";\n\n	while (base--)\n		if (digits[base] == c || digits2[base] == c)\n			return (1);\n	return (0);\n}\n\nint		value_of(char c)\n{\n	if (c >= \'0\' && c <= \'9\')\n		return (c - \'0\');\n	else if (c >= \'a\' && c <= \'f\')\n		return (c - \'a\' + 10);\n	else if (c >= \'A\' && c <= \'F\')\n		return (c - \'A\' + 10);\n	return (0);\n}\n\nint		ft_atoi_base(const char *str, int str_base)\n{\n	int result;\n	int sign;\n\n	result = 0;\n	while (isblank(*str))\n		str++;\n	sign = (*str == \'-\') ? -1 : 1;\n	(*str == \'-\' || *str == \'+\') ? ++str : 0;\n	while (isvalid(*str, str_base))\n		result = result * str_base + value_of(*str++);\n	return (result * sign);\n}\n\nFT_RANGE\n#include <stdlib.h>\n\nint		*ft_range(int min, int max)\n{\n	int		n;\n	int		*s;\n\n	n = max >= min ? max - min : min - max;\n	if (!(s = (int *)malloc(sizeof(int) * (n))))\n		return (NULL);\n	while (max != min)\n		*s++ = max > min ? min++ : min--;\n	*s = min;\n	return (s - n);\n}\n\nPARAMSUM \n#include <unistd.h>\n\nvoid	ft_putchar(char c)\n{\n	write(1, &c, 1);\n}\n\nvoid	ft_putnbr(int n)\n{\n	if (n > 9)\n		ft_putnbr(n / 10);\n	ft_putchar(n %% 10 +\'0\');\n}\n\nint		main(int ac, char **av)\n{\n	av = 0;\n	ft_putnbr(ac - 1);\n	write(1, \"\\n\", 1);\n}\n\nSTR_CAPITALIZER\n#include <unistd.h>\n\nvoid	ft_putchar(char c)\n{\n	write(1, &c, 1);\n}\n\nint		ft_isspace(char c)\n{\n	if (c == \' \' || c == \'\\t\')\n		return (1);\n	return (0);\n}\n\nint		tolower(char c)\n{\n	return (c += (c >= \'A\' && c <= \'Z\') ? 32 : 0);\n}\n\nint		toupper(char c)\n{\n	return (c -= (c >= \'a\' && c <= \'z\') ? 32 : 0);\n}\n\nvoid	str_capitaliser(char *s)\n{\n	while (*s)\n	{\n		while (ft_isspace(*s))\n			ft_putchar(*s++);\n		if (*s && !ft_isspace(*s))\n			ft_putchar(toupper(*s++));\n		while (*s && !ft_isspace(*s))\n			ft_putchar(tolower(*s++));\n	}\n}\n\nint		main(int ac, char **av)\n{\n	if (ac > 1)\n	{\n		++av;\n		while (*av)\n		{\n			str_capitaliser(*av++);\n			write(1, \"\\n\", 1);\n		}\n	}\n	return (0);\n}