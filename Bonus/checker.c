#include "push_swap_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	if (ft_strlen(s1) > ft_strlen(s2))
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	check_line(char *str, t_stack **a, t_stack **b)
{
	if (ft_strcmp(str, "ra\n"))
		rotate_a(a);
	else if (ft_strcmp(str, "rb\n"))
		rotate_b(b);
	else
		print_error();
}

void	apply_instructions(t_stack **a)
{
	char	*str;
	t_stack	*b;

	b = NULL;
	str = get_next_line(0);
	while (str)
	{
		check_line(str, a, &b);
		str = get_next_line(0);
	}
}
