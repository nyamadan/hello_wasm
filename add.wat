(module
  (type $add (func (param i32) (param i32) (result i32)))
  (func $add (type $add) (param $a i32) (param $b i32) (result i32)
    local.get $a
    local.get $b
    i32.add
  )
  (export "add" (func $add))
)