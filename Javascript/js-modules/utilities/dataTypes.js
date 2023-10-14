
/**
 * @function getType
 * function to get real data type 
 * @param {any} any - anyting to check the data type
 * @returns {string} data type name
 */
export function getType (any) {
  if (typeof any === "object" && Array.isArray(any)) return "array";
  if (typeof any === "object" && !Array.isArray(any) && any === null) return "null";
  if (typeof any === "object" && !Array.isArray(any) && any !== null) return "object";
  if (typeof any === "number" && Number.isNaN(any)) return "NaN";
  
  /**
   * if all conditions are met, return whatever value the 'typeof' function returns
   * excepted type of data {string,number,function|undefined|boolean}
   */
  return typeof any;
}

export function getIntermediateType (any) {
  let type = getType(any);
  
  if (type === "number") {
    return isFloat(any) ? "float" : "integer";
  }
  if (type === "array") {
    if (isArrayOfString(any)) return "string[]";
    if (isArrayOfArray(any)) return "array[]";
    if (isArrayOfObject(any)) return "object[]";
    if (isArrayOfNull(any)) return "null[]";
    if (isArrayOfBoolean(any)) return "boolean[]";
    if (isArrayOfNumber(any)) return "number[]";
  }
  
  return type;
}

/**
 * @function isFunction
 * function to check the variable type is function or not
 * @param {any} any - anyting to check the data type
 * @returns {boolean}
 */
export function isFunction (any) {
  return getType(any) === "function";
}

/**
 * @function isArray
 * function to check the variable type is array or not
 * @param {any} any - anyting to check the data type
 * @returns {boolean}
 */
export function isArray (any) {
  return getType(any) === "array";
}

/**
 * @function arrayOfDataType
 * function to check if all items in the array is have same data type
 * @param {Array} array - the array whose item type data will be checked
 * @param {string} type - name of data type to checked
 * @returns {boolean}
 */
export function arrayOfDataType (array, type) {
  if (!isArray(array)) throw new Error(`parameter 1 must array, '${ getType(array) }' given !`);
  if (!isString(type)) throw new Error(`parameter 2 must string, '${ getType(type) }' given !`);
  
  for (let item of array) {
    if (getType(item) !== type) return false;
  }
  
  return true;
}

/**
 * @function isArrayOfString
 * function to check all items in array have string data type or not
 * @param {Array} array - the array whose item type data will be checked
 * @returns {boolean}
 */
export function isArrayOfString (array) {
  if (!isArray(array)) throw new Error(`parameter 1 must array, '${ getType(array) }' given !`);
  
  return arrayOfDataType(array, "string");
}

/**
 * @function isArrayOfNumber
 * function to check all items in array have number data type or not
 * @param {Array} array - the array whose item type data will be checked
 * @returns {boolean}
 */
export function isArrayOfNumber (array) {
  if (!isArray(array)) throw new Error(`parameter 1 must array, '${ getType(array) }' given !`);
  
  return arrayOfDataType(array, "number");
}

/**
 * @function isArrayOfObject
 * function to check all items in array have object data type or not
 * @param {Array} array - the array whose item type data will be checked
 * @returns {boolean}
 */
export function isArrayOfObject (array) {
  if (!isArray(array)) throw new Error(`parameter 1 must array, '${ getType(array) }' given !`);
  
  return arrayOfDataType(array, "object");
}

/**
 * @function isArrayOfArray
 * function to check all items in array have string data type or not
 * @param {Array} array - the array whose item type data will be checked
 * @returns {boolean}
 */
export function isArrayOfArray (array) {
  if (!isArray(array)) throw new Error(`parameter 1 must array, '${ getType(array) }' given !`);
  
  return arrayOfDataType(array, "array");
}

/**
 * @function isArrayOfNull
 * function to check all items in array have null data type or not
 * @param {Array} array - the array whose item type data will be checked
 * @returns {boolean}
 */
export function isArrayOfNull (array) {
  if (!isArray(array)) throw new Error(`parameter 1 must array, '${ getType(array) }' given !`);
  
  return arrayOfDataType(array, "null");
}

/**
 * @function isArrayOfBoolean
 * function to check all items in array have boolean data type or not
 * @param {Array} array - the array whose item type data will be checked
 * @returns {boolean}
 */
export function isArrayOfBoolean (array) {
  if (!isArray(array)) throw new Error(`parameter 1 must array, '${ getType(array) }' given !`);
  
  return arrayOfDataType(array, "boolean");
}

/**
 * @function isObject
 * function to check the variable type is object or not
 * @param {any} any - anyting to check the data type
 * @returns {boolean}
 */
export function isObject (any) {
  return getType(any) === "object";
}

/**
 * @function isNull
 * function to check the variable type is null or not
 * @param {any} any - anyting to check the data type
 * @returns {boolean}
 */
export function isNull (any) {
  return getType(any) === "null";
}

/**
 * @function isUndefined
 * function to check the variable type is undefined or not
 * @param {any} any - anyting to check the data type
 * @returns {boolean}
 */
export function isUndefined (any) {
  return getType(any) === "undefined";
}

/**
 * @function isBoolean
 * function to check the variable type is boolean or not
 * @param {any} any - anyting to check the data type
 * @returns {boolean}
 */
export function isBoolean (any) {
  return getType(any) === "";
}

/**
 * @function isNumber
 * function to check the variabel is number or not
 * @param {any} any - anyting to check the data type
 * @returns {boolean}
 */
export function isNumber(any) {
  return getType(any) === "number";
}

/**
 * @function isInteger
 * function to check the number is integer or not
 * @param {any} any - anyting to check the data type
 * @returns {boolean}
 */
export function isInteger (any) {
  return getType(any) === "number" && any % 1 === 0;
}

/**
 * @function isInteger
 * function to check the number is float or not
 * @param {any} any - anyting to check the data type
 * @returns {boolean}
 */
export function isFloat (any) {
  return getType(any) === "number" && any % 1 > 0;
}

/**
 * @function isString
 * function to check the variable type is string or not
 * @param {any} any - anyting to check the data type
 * @returns {boolean}
 */
export function isString (any) {
  return getType(any) === "string";
}

export function isContainTypes (any, types) {
  if (!["string", "array"].includes(getType(types))) throw `parameter 2 must be type string|array, '${ getType(types) }'' given !`;
  
  let dataTypes = [];
  let SPLITTER_REGEX = /(\||\,|\s)/g;
  
  if (!isString(types)) dataTypes = types.split(SPLITTER_REGEX);
  
  return dataTypes.includes(getIntermediateType(any));
}