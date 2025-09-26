#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tushu.h"

Book library[MAX_BOOKS];
int book_count = 0;

void add_book()
{
    if (book_count >= MAX_BOOKS) 
	{
        printf("图书馆已满，无法添加更多图书！\n");
        return;
    }
    
    Book new_book;
    printf("\n--- 添加图书 ---\n");
    printf("请输入图书ID: ");
    scanf("%d", &new_book.id);
    int i;
    for (i = 0; i < book_count; i++)
	{
        if (library[i].id == new_book.id) 
		{
            printf("该ID已存在，请使用其他ID！\n");
            return;
        }
    }
    
    printf("请输入书名: ");
    scanf("%s", new_book.title);
    printf("请输入作者: ");
    scanf("%s", new_book.author);
    printf("请输入出版年份: ");
    scanf("%d", &new_book.year);
    new_book.is_borrowed = 0;
    
    library[book_count++] = new_book;
    printf("图书添加成功！\n");
}
int i;
void display_books()
{
    printf("\n--- 图书列表 ---\n");
    printf("ID\t书名\t\t作者\t\t年份\t状态\n");
    printf("------------------------------------------------\n");
    
    for (i = 0; i < book_count; i++) 
	{
        printf("%d\t%s\t\t%s\t\t%d\t%s\n", 
               library[i].id, 
               library[i].title, 
               library[i].author, 
               library[i].year,
               library[i].is_borrowed ? "已借出" : "可借阅");
    }
    
    if (book_count == 0)
	{
        printf("图书馆中没有图书！\n");
    }
}

void search_book()
{
    int option;
    printf("\n--- 搜索图书 ---\n");
    printf("1. 按ID搜索\n");
    printf("2. 按书名搜索\n");
    printf("3. 按作者搜索\n");
    printf("请选择搜索方式: ");
    scanf("%d", &option);
    char search_term[MAX_TITLE_LEN];
    int search_id;
    int found = 0;
    int i;
    switch (option)
	{
        case 1:
            printf("请输入图书ID: ");
            scanf("%d", &search_id);
            for (i = 0; i < book_count; i++)
			{
                if (library[i].id == search_id) 
				{
                    printf("\n找到图书:\n");
                    printf("ID: %d\n书名: %s\n作者: %s\n年份: %d\n状态: %s\n",
                           library[i].id, library[i].title, library[i].author,
                           library[i].year, library[i].is_borrowed ? "已借出" : "可借阅");
                    found = 1;
                    break;
                }
            }
            break;
            
        case 2:
            printf("请输入书名: ");
            scanf("%s", search_term);
            printf("\n搜索结果:\n");
            for (i = 0; i < book_count; i++) 
			{
                if (strstr(library[i].title, search_term) != NULL) 
				{
                    printf("ID: %d, 书名: %s, 作者: %s, 年份: %d, 状态: %s\n",
                           library[i].id, library[i].title, library[i].author,
                           library[i].year, library[i].is_borrowed ? "已借出" : "可借阅");
                    found = 1;
                }
            }
            break;
        case 3:
            printf("请输入作者名: ");
            scanf("%s", search_term);
            printf("\n搜索结果:\n");
            for (i = 0; i < book_count; i++)
			{
                if (strstr(library[i].author, search_term) != NULL) 
				{
                    printf("ID: %d, 书名: %s, 作者: %s, 年份: %d, 状态: %s\n",
                           library[i].id, library[i].title, library[i].author,
                           library[i].year, library[i].is_borrowed ? "已借出" : "可借阅");
                    found = 1;
                }
            }
            break;
            
        default:
            printf("无效选择！\n");
            return;
    }
    
    if (!found) 
	{
        printf("未找到匹配的图书！\n");
    }
}

void borrow_book() 
{
    int book_id;
    printf("\n--- 借阅图书 ---\n");
    printf("请输入要借阅的图书ID: ");
    scanf("%d", &book_id);
    int i;
    for (i = 0; i < book_count; i++)
	{
        if (library[i].id == book_id)
		{
            if (library[i].is_borrowed)
			{
                printf("该书已被借出！\n");
            }
			else
			{
                library[i].is_borrowed = 1;
                printf("成功借阅图书: %s\n", library[i].title);
            }
            return;
        }
    }
    
    printf("未找到ID为%d的图书！\n", book_id);
}

void return_book() {
    int book_id;
	int i;
    printf("\n--- 归还图书 ---\n");
    printf("请输入要归还的图书ID: ");
    scanf("%d", &book_id);    
    for (i = 0; i < book_count; i++) 
	{
		if (library[i].id == book_id) 
		{
            if (!library[i].is_borrowed) 
			{
                printf("该书未被借出！\n");
            } 
			else 
			{
                library[i].is_borrowed = 0;
                printf("成功归还图书: %s\n", library[i].title);
            }
            return;
        }
    }
    printf("未找到ID为%d的图书！\n", book_id);
}
