/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 14:17:16 by mpetruse          #+#    #+#             */
/*   Updated: 2018/09/17 14:17:51 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <string.h>
# include <stdio.h>

/*--------------------------------
  !! required structure
--------------------------------*/

struct  s_art {
    char *name;
    int price;
};


/*--------------------------------
  :) function you must implement
--------------------------------*/

int  searchPrice(struct s_art **arts, char *name);


/*--------------------------------
  ?? test function used in main 
--------------------------------*/

struct s_art		**getArts(void);


/*--------------------------------
  &  your own other function
--------------------------------*/


#endif
