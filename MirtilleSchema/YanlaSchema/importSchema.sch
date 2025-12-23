Rust: mod hello;

Ada: with Ada.Text_IO; use Ada.Text_IO;

Erlang: -import('parser', [functions]).

Ocaml: use "my_module.ml";;

Ocaml: open List

Prolog: use_module(library(lists)).

Java: import java.util.*;

Go: import (
    "log"
    "net/http"
    "myapp/common"
    "myapp/routers"
)

Nodejs: const f = require('./func');

VB.net: Imports CtrlChrs = Microsoft.VisualBasic.ControlChars

c++: import math;


= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Yanla Importation System (YISYS):
--------------------

Yanla : from <iostream> import namespace.subnamespace

	from "myModule.hyl" import namespace.subnamespace

	import ("ai.matrices" "ai.math" "system.fork")

	import ai.namespace.subnamespace.train as ai_train

	from @("url1" "url2" "urln")@ import ("function1" "function2")

	from @#("api1" "api2" "api3")#@ import ("index1" "index2" "indexn") as (search1, data_training, cpu)

	import A
	
	from exported "./" import * 

-- Importation par correspondance (importation brute-force : importation par reconnaissance):
	export from "myvalue" to "mykey"
	from key "mykey" import matching "myvalue"

	--
	export "myvalue" to *
	from key * import matching "myvalue"


