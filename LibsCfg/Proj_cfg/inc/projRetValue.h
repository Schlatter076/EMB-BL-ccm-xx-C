#ifndef __PROJECT_RETVALUE_H_20190414YK
#define __PROJECT_RETVALUE_H_20190414YK

#ifdef __cplusplus
extern"C"{
#endif

#define __RET_VAL_DEFINED

typedef long RET_VAL_TYPE;

#define RET_CLASS_MASK        (0xF0000000)//类型掩码

#define RET_PRIVATE_TYPE      (0xF0000000)//私有类型，由应用程序自行决定含义
#define RET_SUCCESS_TYPE      (0x00000000)//成功
#define RET_WARNING_TYPE      (0x10000000)//警告
#define RET_ERROR_TYPE        (0x20000000)//一般错误
#define RET_FAULT_TYPE        (0x30000000)//严重错误
#define RET_PLUS_NUMBER_TYPE  (0x40000000)//正整数和0
#define RET_MINUS_NUMBER_TYPE (0x50000000)//负整数和0
#define RET_EXIT_TYPE         (0x60000000)//退出(调用者应该退出)

#define RET_SUCCESS_FALSE     (RET_SUCCESS_TYPE|0)
#define RET_SUCCESS_TRUE      (RET_SUCCESS_TYPE|1)
#define RET_SUCCESS_SUCCESS   (RET_SUCCESS_TYPE|2)

#define RET_WARNING_GENERAL   (RET_WARNING_TYPE|1)
#define RET_WARNING_PENDING   (RET_WARNING_TYPE|2)//操作正在进行中

#define RET_ERROR_INTRNAL     (RET_ERROR_TYPE|1)//程序不可能出错的地方出错。类似ASSERT
#define RET_ERROR_GENERAL     (RET_ERROR_TYPE|2)
#define RET_ERROR_FAILED      (RET_ERROR_TYPE|3)
#define RET_ERROR_NOMEMORY    (RET_ERROR_TYPE|4)
#define RET_ERROR_POINTER     (RET_ERROR_TYPE|5)
#define RET_ERROR_SMALL_BUF   (RET_ERROR_TYPE|6)
#define RET_ERROR_FALSE       (RET_ERROR_TYPE|7)
#define RET_ERROR_TRUE        (RET_ERROR_TYPE|8)

#define RET_FAULT_INTRNAL     (RET_FAULT_TYPE|1)//程序不可能出错的地方出了严重错误。
#define RET_FAULT_GENERAL     (RET_FAULT_TYPE|2)

#define RET_EXIT_INTRNAL      (RET_EXIT_TYPE|1)//程序出错
#define RET_EXIT_GENERAL      (RET_EXIT_TYPE|2)//调用者完成使命，应该退出了

#define RET_IS_CLASS(RET_CLASS,RETURN_VALUE) \
	(((RET_CLASS_MASK)&(RETURN_VALUE))==(RET_CLASS))

#define RET_IS_SUCCESS(RETURN_VALUE) \
	(RET_IS_CLASS(RET_SUCCESS_TYPE,RETURN_VALUE))

//注意：形如RET_IS_SUCCESS_OR_WARNING(fun())或者RET_IS_SUCCESS_OR_WARNING(i++)等方式很可能出错。
#define RET_IS_SUCCESS_OR_WARNING(RETURN_VALUE) \
	(RET_IS_SUCCESS(RETURN_VALUE)||RET_IS_CLASS(RET_WARNING_TYPE,RETURN_VALUE))

//注意：形如RET_IS_ERROR(fun())或者RET_IS_ERROR(i++)等方式很可能出错。
#define RET_IS_ERROR(RETURN_VALUE) \
	(RET_IS_CLASS(RET_ERROR_TYPE,RETURN_VALUE)||\
	RET_IS_CLASS(RET_FAULT_TYPE,RETURN_VALUE))

//注意：形如RET_IS_NUMBER(fun())或者RET_IS_NUMBER(i++)等方式很可能出错。
#define RET_IS_NUMBER(RETURN_VALUE)  (RET_IS_CLASS(RET_PLUS_NUMBER_TYPE,RETURN_VALUE) ||\
                                      RET_IS_CLASS(RET_MINUS_NUMBER_TYPE,RETURN_VALUE))

//注意：形如RET_GET_NUM(fun())或者RET_GET_NUM(i++)等方式很可能出错。
//对于RET_PLUS_NUMBER_TYPE和RET_MINUS_NUMBER_TYPE类型数据，得到真正的数值。
//其他类型返回0
#define RET_GET_NUM(RETURN_VALUE) \
	(RET_IS_CLASS(RET_PLUS_NUMBER_TYPE,RETURN_VALUE)?\
		(long)((RETURN_VALUE)-RET_PLUS_NUMBER_TYPE)\
	:RET_IS_CLASS(RET_MINUS_NUMBER_TYPE,RETURN_VALUE)?\
		-(long)((RETURN_VALUE)-RET_MINUS_NUMBER_TYPE)\
	:(long)0)

//注意：形如RET_GEN_NUM(fun())或者RET_GEN_NUM(i++)等方式很可能出错。
//注意2：对于0，编码成RET_PLUS_NUMBER_TYPE类型数据。
//从long产生返回值类型，如果超过返回值类型表达范围，生成RET_ERROR_GENERAL
#define RET_GEN_NUM(NUMBER_VALUE) \
	(\
		(NUMBER_VALUE)>=0?\
		(\
			RET_CLASS_MASK&(NUMBER_VALUE)?\
				RET_ERROR_GENERAL\
			:RET_PLUS_NUMBER_TYPE|(NUMBER_VALUE)\
		)\
		:\
			RET_GEN_MINUS_NUM(NUMBER_VALUE)\
	)

//注意：形如RET_GEN_MINUS_NUM(fun())或者RET_GEN_MINUS_NUM(i++)等方式很可能出错。
//从long产生返回值类型，如果超过返回值类型表达范围或者为正整数，生成RET_ERROR_GENERAL
#define RET_GEN_MINUS_NUM(NUMBER_VALUE) \
	(\
		(NUMBER_VALUE)>0?RET_ERROR_GENERAL\
		:\
		(\
			((-1l-(long)((unsigned long)-1l>>1))==(long)(NUMBER_VALUE))\
				||(RET_CLASS_MASK&(-(long)(NUMBER_VALUE)))?\
				RET_ERROR_GENERAL\
			:RET_MINUS_NUMBER_TYPE|(-(long)(NUMBER_VALUE))\
		)\
	)

//该宏规避了副作用。
//RETURN_VALUE[in]：RET_PLUS_NUMBER_TYPE和RET_MINUS_NUMBER_TYPE类型数据
//NUMBER_VALUE[out]：接收转换后的数值。
//对于RET_PLUS_NUMBER_TYPE和RET_MINUS_NUMBER_TYPE类型数据，得到真正的(long)数值。
//其他类型转换成0
#define RET_GET_NUMBER(RETURN_VALUE,NUMBER_VALUE) \
{\
	long val=RETURN_VALUE;\
	NUMBER_VALUE=RET_GET_NUM(val);\
}

//该宏规避了副作用。
//从真正的(long)数值产生返回值类型，如果超过返回值类型表达范围，生成RET_ERROR_GENERAL
//NUMBER_VALUE[in]：转换前的真正的(long)数值。
//RETURN_VALUE[out]：RET_PLUS_NUMBER_TYPE或者RET_MINUS_NUMBER_TYPE类型数据
//或者RET_ERROR_GENERAL
#define RET_GEN_NUMBER(NUMBER_VALUE,RETURN_VALUE) \
{\
	long val=NUMBER_VALUE;\
	RETURN_VALUE=RET_GEN_NUM(val);\
}

//该宏规避了副作用。
//从真正的(long)数值产生返回值类型，如果超过返回值类型表达范围，生成RET_ERROR_GENERAL
//NUMBER_VALUE[in]：转换前的真正的(long)数值。
//RETURN_VALUE[out]：RET_MINUS_NUMBER_TYPE类型数据或者RET_ERROR_GENERAL
#define RET_GEN_MINUS_NUMBER(NUMBER_VALUE,RETURN_VALUE) \
{\
	long val=NUMBER_VALUE;\
	RETURN_VALUE=RET_GEN_MINUS_NUM(val);\
}

#ifdef __cplusplus
}
#endif

#endif // __PROJECT_RETVALUE_H_20190414YK
