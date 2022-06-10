/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:13:06 by youkim            #+#    #+#             */
/*   Updated: 2022/05/04 15:07:18 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "renderer.h"
#include "parser.h"
#include <stdio.h> // FIXME: remove
int	main(int argc, t_const_string argv[])
{
	t_parser	parser;
	t_world		world;
	t_engine	engine;

	if (argc != 2)
		std__panic__value("main", "usage: ./cub3d.out <cub_file>.cub");
	parser__init(&parser, argv[1]);
	parser__parse(&parser, &world);
	engine__init(&engine, &world);
	engine__run(&engine);
	return (0);
}
