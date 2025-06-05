/**
 * @param {*} obj
 * @param {*} classFunction
 * @return {boolean}
 */
var checkIfInstanceOf = function(obj, classFunction) {
    if(obj == null || classFunction == null || obj == undefined || classFunction == [] || typeof(classFunction) !== 'function') return false;
    console.log(1);
    return Object(obj)instanceof(classFunction);
};

/**
 * checkIfInstanceOf(new Date(), Date); // true
 */