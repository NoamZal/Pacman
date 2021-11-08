#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <process.h>

using namespace std;

const char UP1 = 'w'; // Up Arrow 
const char UP2 = 'W'; // Up Arrow 
const char DOWN1 = 'x'; // Down Arrow 
const char DOWN2 = 'X'; // Down Arrow 
const char LEFT1 = 'a';  // Left Arrow 
const char LEFT2 = 'A';  // Left Arrow 
const char RIGHT1 = 'd';// Right Arrow 
const char RIGHT2 = 'D';// Right Arrow 
const char STAY1 = 's';// Stay Arrow 
const char STAY2 = 'S';// Stay Arrow 
const char ESC = 27;  // Escape Key

const char  COLS = 80;
const char  ROWS = 24;
const char  WALL = '#';
const char  BLANK = ' ';
const char  BREADCRUMB = '*';

const char LIVES = 3;
const char SIGN = '@';

const char GSIGN = '&';
const char SPECIAL_TUNNEL = '^';