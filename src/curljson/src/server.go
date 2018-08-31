package main

import (
	"encoding/json"
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
)

type FavoriteLanguage struct {
	Name      string   `json:"name"`
	Languages []string `json:"languages"`
}

type Book struct {
	Name string `json:"name"`
}

type Person struct {
	Name  string `json:"name"`
	Age   int    `json:"age"`
	Books []Book `json:"books"`
}

func favor(w http.ResponseWriter, req *http.Request) {
	body, err := ioutil.ReadAll(req.Body)
	if err != nil {
		fmt.Println("ioutil.ReadAll Error", err)
		return
	}
	defer req.Body.Close()

	var p Person
	if err = json.Unmarshal([]byte(body), &p); err != nil {
		fmt.Println("json.Unmarshal Error", err)
		fmt.Println(string(body))
		result := "{\"code\":400, \"msg\":\"ok\"}"
		w.Write([]byte(result))
		return
	}

	fmt.Printf("person=%+v\n", p)

	favorLan := FavoriteLanguage{
		Name:      p.Name,
		Languages: []string{"C++", "Golang", "Python"},
	}

	data, err := json.Marshal(favorLan)
	if err != nil {
		fmt.Printf("Marshal Error %v, favor:%v", err, favorLan)
		return
	}
	w.Write([]byte(data))
}

func main() {
	addr := "0.0.0.0:9999"
	http.HandleFunc("/favorbooks", favor)
	fmt.Println("Listen", addr)
	if err := http.ListenAndServe(addr, nil); err != nil {
		log.Fatal("ListenAndServe: ", err)
	}
}
