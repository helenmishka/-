#include <stdio.h>
#include <string.h>
#include "ui.h"
#include <stdlib.h>

#include "struct.h"

#include "main_funcs.h"
#include "codes_errors.h"
#include "io.h"
#include "memory.h"

static uiBox *vbox;
static uiForm *entryForm;
static uiForm *resForm;
static uiEntry *date;
static uiEntry *surname;
static uiEntry *test;
static uiButton *but_add;
static uiButton *but_del;
static uiButton *print_res;
static uiMultilineEntry *res;
static uiWindow *mainwin;

static experiments_t *exp;
static int size = 0;
static int ind = 0;
static int flag = 0;


static int onClosing(uiWindow *w, void *data)
{
	uiQuit();
	return 1;
}

static int onShouldQuit(void *data)
{
	uiWindow *mainwin = uiWindow(data);

	uiControlDestroy(uiControl(mainwin));
	return 1;
}

int read_array_exp(experiments_t **exp)
{
	if (flag == 0)
	{
		allocate_struct(exp);
		flag = 1;
	}
	resize_exp(exp, (size + 1));
	int check;
	check = read_date(*exp, ind, date);
	if (check == INPUT_ERROR)
		return ERR;
	if (read_surname(*exp, ind, surname) != OK)
	{
		free((*exp)[ind].date);
		return ERR;
	}
	if (read_test(*exp, ind, test) != OK)
	{
		free((*exp)[ind].date);
		free((*exp)[ind].surname);
		return ERR;
	}
	ind++;
	size++;
    
    return OK;
}

static void onAddClicked(uiButton *b, void *data)
{
	uiMultilineEntrySetText(res,"");
	if (read_array_exp(&exp) != OK)
		uiMsgBoxError(mainwin,
		"ОШИБКА",
		"НЕВЕРНЫЙ ВВОД!");
	else
		uiMsgBox(mainwin,
		"ОК",
		"ВВОД УСПЕШНО ВЫПОЛНЕН!");
}
static void onDelClicked(uiButton *b, void *data)
{
	uiMultilineEntrySetText(res,"");
	if (size == 0)
		uiMsgBoxError(mainwin,
		"ОШИБКА",
		"ВВЕДИТЕ ДАННЫЕ!");
	else if(del_exp(&exp, &size, &ind) != OK)
		uiMsgBoxError(mainwin,
		"ОШИБКА",
		"МАССИВ ЗАПИСЕЙ ПУСТ!");
}
static void onPrintClicked(uiButton *b, void *data)
{
	if (size == 0)
		uiMsgBoxError(mainwin,
		"ОШИБКА",
		"ВВЕДИТЕ ДАННЫЕ!");
	uiMultilineEntrySetText(res, "");
	for (int i = 0; i < size; i++)
	{
		uiMultilineEntryAppend(res, exp[i].date);
		uiMultilineEntryAppend(res, "\n");
		uiMultilineEntryAppend(res, exp[i].surname);
		uiMultilineEntryAppend(res, "\n");
		uiMultilineEntryAppend(res, exp[i].test);
		uiMultilineEntryAppend(res, "\n");
		uiMultilineEntryAppend(res, "-------------------------------------------\n");
	}
}

static uiControl *makeBasicControlsPage(void)
{
	vbox = uiNewVerticalBox();
	uiBoxSetPadded(vbox, 1);
	
	entryForm = uiNewForm();
	uiFormSetPadded(entryForm, 1);
	uiBoxAppend(vbox, uiControl(entryForm), 1);
	date = uiNewEntry();
	uiFormAppend(entryForm,
		"Дата проведения",
		uiControl(date),
		0);
	surname = uiNewEntry();
	uiFormAppend(entryForm,
		"Фамилия",
		uiControl(surname),
		0);
	test = uiNewEntry();
	uiFormAppend(entryForm,
		"Показания эксперимента",
		uiControl(test),
		0);
	but_add = uiNewButton("Добавить запись");
	uiFormAppend(entryForm,"",
		uiControl(but_add),
		1);
	uiBoxAppend(vbox,
		uiControl(uiNewHorizontalSeparator()),
		0);
		
	resForm = uiNewForm();
	uiFormSetPadded(resForm, 2);
	uiBoxAppend(vbox, uiControl(resForm), 1);
	
	but_del = uiNewButton("Удалить эксперименты, проведенные не позже 1 февраля 1993");
	uiFormAppend(resForm,"",
		uiControl(but_del),
		0);
	print_res = uiNewButton("Вывести массив записей");
	uiFormAppend(resForm,"",
		uiControl(print_res),
		0);
	res = uiNewMultilineEntry();
	uiFormAppend(resForm,
		"Результат",
		uiControl(res),
		1);
	uiButtonOnClicked(but_add, onAddClicked, NULL);
	uiButtonOnClicked(but_del, onDelClicked, NULL);
	uiButtonOnClicked(print_res, onPrintClicked, NULL);

	return uiControl(vbox);
}

int main(void)
{
	uiInitOptions options;
	const char *err;
	uiTab *tab;

	memset(&options, 0, sizeof (uiInitOptions));
	err = uiInit(&options);
	if (err != NULL) {
		fprintf(stderr, "error initializing libui: %s", err);
		uiFreeInitError(err);
		return 1;
	}

	mainwin = uiNewWindow("Лабораторная работа 14", 640, 480, 1);
	uiWindowOnClosing(mainwin, onClosing, NULL);
	uiOnShouldQuit(onShouldQuit, mainwin);

	tab = uiNewTab();
	uiWindowSetChild(mainwin, uiControl(tab));
	uiWindowSetMargined(mainwin, 1);

	uiTabAppend(tab, "Кайф", makeBasicControlsPage());
	uiTabSetMargined(tab, 0, 1);

	uiControlShow(uiControl(mainwin));
	uiMain();
	free_struct(exp, size);
	return 0;
}
