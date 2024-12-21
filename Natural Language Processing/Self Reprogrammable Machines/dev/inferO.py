from transformers import AutoModelForCausalLM, AutoTokenizer

model_path = "nvidia/Mistral-NeMo-Minitron-8B-Base"
tokenizer = AutoTokenizer.from_pretrained(model_path)
model = AutoModelForCausalLM.from_pretrained(
    model_path,
    device_map="auto",
    offload_folder="offload"
)
inputs = tokenizer("Hello, how are you?", return_tensors="pt")
outputs = model.generate(inputs.input_ids, max_length=25)
print(tokenizer.decode(outputs[0]))