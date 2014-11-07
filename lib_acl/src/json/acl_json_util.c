#include "StdAfx.h"
#include <stdio.h>
#ifndef ACL_PREPARE_COMPILE
#include "stdlib/acl_iterator.h"
#include "stdlib/acl_vstring.h"
#include "stdlib/acl_mystring.h"
#include "stdlib/acl_array.h"
#include "stdlib/acl_argv.h"
#include "stdlib/acl_msg.h"
#include "json/acl_json.h"
#endif

#define STR	acl_vstring_str
#define	LEN	ACL_VSTRING_LEN

void acl_json_free_array(ACL_ARRAY *a)
{
	acl_array_destroy(a, NULL);
}

ACL_ARRAY *acl_json_getElementsByTagName(ACL_JSON *json, const char *tag)
{
	ACL_ITER iter;
	ACL_ARRAY *a = acl_array_create(10);

	acl_foreach(iter, json) {
		ACL_JSON_NODE *node = (ACL_JSON_NODE*) iter.data;
		if (strcasecmp(tag, STR(node->ltag)) == 0) {
			acl_array_append(a, node);
		}
	}

	if (acl_array_size(a) == 0) {
		acl_array_destroy(a, NULL);
		return (NULL);
	}

	return (a);
}

ACL_ARRAY *acl_json_getElementsByTags(ACL_JSON *json, const char *tags)
{
	ACL_ARGV *tokens = acl_argv_split(tags, "/");
	ACL_ARRAY *a, *result;
	ACL_ITER iter;
	ACL_JSON_NODE *node_saved, *node;
	int   i;

	a = acl_json_getElementsByTagName(json, tokens->argv[tokens->argc - 1]);
	if (a == NULL) {
		acl_argv_free(tokens);
		return (NULL);
	}

	result = acl_array_create(acl_array_size(a));

#define	NEQ(x, y) strcasecmp((x), (y))

	acl_foreach(iter, a) {
		node = (ACL_JSON_NODE*) iter.data;
		node_saved = node;
		i = tokens->argc - 1;
		while (i >= 0 && node->parent != NULL) {
			if (node->left_ch != 0) {
				node = node->parent;
			} else if (NEQ(tokens->argv[i], "*")
				&& NEQ(tokens->argv[i], STR(node->ltag)))
			{
				break;
			} else {
				i--;
				node = node->parent;
			}
		}
		if (i == -1)
			result->push_back(result, node_saved);
	}

	acl_json_free_array(a);
	acl_argv_free(tokens);

	if (acl_array_size(result) == 0) {
		acl_array_free(result, NULL);
		result = NULL;
	}
	return result;
}

#define LEN	ACL_VSTRING_LEN
#define STR	acl_vstring_str

ACL_JSON_NODE *acl_json_create_text(ACL_JSON *json,
	const char *name, const char *value)
{
	ACL_JSON_NODE *node = acl_json_node_alloc(json);

	acl_vstring_strcpy(node->ltag, name);
	acl_vstring_strcpy(node->text, value);
	node->type = ACL_JSON_T_TEXT;
	return (node);
}

ACL_JSON_NODE *acl_json_create_bool(ACL_JSON *json,
	const char *name, int value)
{
	ACL_JSON_NODE *node = acl_json_node_alloc(json);

	acl_vstring_strcpy(node->ltag, name);
	acl_vstring_strcpy(node->text, value == 0 ? "false" : "true");
	node->type = ACL_JSON_T_BOOL;
	return (node);
}

ACL_JSON_NODE *acl_json_create_int64(ACL_JSON *json,
	const char *name, acl_int64 value)
{
	ACL_JSON_NODE *node = acl_json_node_alloc(json);

	acl_vstring_strcpy(node->ltag, name);
	acl_vstring_sprintf(node->text, "%lld", value);
	node->type = ACL_JSON_T_NUMBER;
	return (node);
}

ACL_JSON_NODE *acl_json_create_string(ACL_JSON *json, const char *text)
{
	ACL_JSON_NODE *node = acl_json_node_alloc(json);

	acl_vstring_strcpy(node->text, text);
	node->type = ACL_JSON_T_STRING;
	return (node);
}

ACL_JSON_NODE *acl_json_create_obj(ACL_JSON *json)
{
	ACL_JSON_NODE *node = acl_json_node_alloc(json);

	node->left_ch = '{';
	node->right_ch = '}';
	node->type = ACL_JSON_T_OBJ;
	return (node);
}

ACL_JSON_NODE *acl_json_create_array(ACL_JSON *json)
{
	ACL_JSON_NODE *node = acl_json_node_alloc(json);

	node->left_ch = '[';
	node->right_ch = ']';
	node->type = ACL_JSON_T_ARRAY;
	return (node);
}

ACL_JSON_NODE *acl_json_create_node(ACL_JSON *json,
	const char *name, ACL_JSON_NODE *value)
{
	ACL_JSON_NODE *node = acl_json_node_alloc(json);

	acl_vstring_strcpy(node->ltag, name);
	node->tag_node = value;
	node->type = ACL_JSON_T_OBJ;
	acl_json_node_add_child(node, value);
	return (node);
}

void acl_json_node_append_child(ACL_JSON_NODE *parent, ACL_JSON_NODE *child)
{
	const char *myname = "acl_json_node_append_child";

	if (parent->type != ACL_JSON_T_ARRAY
		&& parent->type != ACL_JSON_T_OBJ
		&& parent != parent->json->root)
	{
		acl_msg_fatal("%s(%d): parent's type not array or obj",
			myname, __LINE__);
	}
	acl_json_node_add_child(parent, child);
}

static void json_escape_append(ACL_VSTRING *buf, const char *src)
{
	const unsigned char *ptr = (const unsigned char*) src;

	ACL_VSTRING_ADDCH(buf, '"');

	while (*ptr) {
		if (*ptr == '"' || *ptr == '\\' || *ptr == '/') {
			ACL_VSTRING_ADDCH(buf, '\\');
			ACL_VSTRING_ADDCH(buf, *ptr);
		} else if (*ptr == '\b') {
			ACL_VSTRING_ADDCH(buf, '\\');
			ACL_VSTRING_ADDCH(buf, 'b');
		} else if (*ptr == '\f') {
			ACL_VSTRING_ADDCH(buf, '\\');
			ACL_VSTRING_ADDCH(buf, 'f');
		} else if (*ptr == '\n') {
			ACL_VSTRING_ADDCH(buf, '\\');
			ACL_VSTRING_ADDCH(buf, 'n');
		} else if (*ptr == '\r') {
			ACL_VSTRING_ADDCH(buf, '\\');
			ACL_VSTRING_ADDCH(buf, 'r');
		} else if (*ptr == '\t') {
			ACL_VSTRING_ADDCH(buf, '\\');
			ACL_VSTRING_ADDCH(buf, 't');
		} else
			ACL_VSTRING_ADDCH(buf, *ptr);
		ptr++;
	}
	ACL_VSTRING_ADDCH(buf, '"');
	ACL_VSTRING_TERMINATE(buf);
}

ACL_VSTRING *acl_json_build(ACL_JSON *json, ACL_VSTRING *buf)
{
	ACL_JSON_NODE *node, *prev;
	ACL_ITER iter;

	if (buf == NULL)
		buf = acl_vstring_alloc(256);

	if (json->root->left_ch > 0) {
		ACL_VSTRING_ADDCH(buf, json->root->left_ch);
		ACL_VSTRING_TERMINATE(buf);
	}

	acl_foreach(iter, json) {
		node = (ACL_JSON_NODE*) iter.data;
		prev = acl_json_node_prev(node);
		if (prev != NULL)
			acl_vstring_strcat(buf, ", ");

		/* 只有当标签的对应值为 JSON 对象或数组对象时 tag_node 非空 */
		if (node->tag_node != NULL) {
			if (LEN(node->ltag) > 0) {
				json_escape_append(buf, STR(node->ltag));
				ACL_VSTRING_ADDCH(buf, ':');
				ACL_VSTRING_ADDCH(buf, ' ');
			}
			if (node->left_ch != 0) {
				/* '{' or '[' */	
				ACL_VSTRING_ADDCH(buf, node->left_ch);
			}
		}

		/* 当结点有标签名时 */
		else if (LEN(node->ltag) > 0) {
			json_escape_append(buf, STR(node->ltag));
			ACL_VSTRING_ADDCH(buf, ':');
			ACL_VSTRING_ADDCH(buf, ' ');
			switch (node->type) {
			case ACL_JSON_T_BOOL:
			case ACL_JSON_T_NUMBER:
				acl_vstring_strcat(buf, STR(node->text));
				break;
			default:
				json_escape_append(buf, STR(node->text));
				break;
			}
		}

		/* 当结点为数组的字符串成员时 */
		else if (LEN(node->text) > 0 && node->parent
			&& node->parent->left_ch != 0)
		{
			json_escape_append(buf, STR(node->text));
		}

		/* 当结点为没有标签名的容器(为 '{}' 或 '[]')时 */
		else if (node->left_ch != 0) {
			ACL_VSTRING_ADDCH(buf, node->left_ch);
		}

		/* 当本结点有子结点或虽为叶结点，但该结点的下一个兄弟结点
		 * 非空时继续下一个循环过程
		 */
		if (acl_json_node_next(node) != NULL
			|| acl_ring_size(&node->children) > 0)
		{
			continue;
		}

		/* 当本结点为叶结点且后面没有兄弟结点时，需要一级一级回溯
		 * 将父结点的分隔符添加至本叶结点尾部，直到遇到根结点或父
		 * 结点的下一个兄弟结点非空
		 */
		while (node != node->json->root
			&& acl_json_node_next(node) == NULL)
		{
			if (node->parent->right_ch != 0) {
				/* right_ch: '}' or ']' */
				ACL_VSTRING_ADDCH(buf, node->parent->right_ch);
			}
			node = node->parent;
		}
	}

	ACL_VSTRING_TERMINATE(buf);
	return buf;
}

ACL_VSTRING *acl_json_node_build(ACL_JSON_NODE *node, ACL_VSTRING *buf)
{
	ACL_JSON *json = acl_json_alloc();
	ACL_JSON_NODE *first;

	if (buf == NULL)
		buf = acl_vstring_alloc(256);

	if (node == node->json->root && node->tag_node != NULL)
		node = node->tag_node;
	else
		json->root->left_ch = json->root->right_ch = 0;

	first = acl_json_node_duplicate(json, node);
	acl_json_node_add_child(json->root, first);
	acl_json_build(json, buf);
	acl_json_free(json);

	return buf;
}
