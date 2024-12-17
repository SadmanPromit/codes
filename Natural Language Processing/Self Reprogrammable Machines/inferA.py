import torch
from transformers import AutoTokenizer, AutoModelForCausalLM, AutoConfig
from accelerate import init_empty_weights, load_checkpoint_and_dispatch

model_path = "C:/Users/proom/.cache/huggingface/hub/models--nvidia--Mistral-NeMo-Minitron-8B-Base/snapshots/cc94637b669b62c4829b1e0c3b9074fecd883b74/"
config_path = model_path + "config.json"
tokenizer = AutoTokenizer.from_pretrained(model_path)
config = AutoConfig.from_pretrained(config_path)
with init_empty_weights():
    model = AutoModelForCausalLM.from_config(config, torch_dtype=torch.bfloat16)
model = load_checkpoint_and_dispatch(
    model,
    checkpoint=model_path,
    device_map="auto",
    offload_folder="offload_directory",
    offload_state_dict=True
)
input_text = "Once upon a time,"
inputs = tokenizer(input_text, return_tensors="pt").to("cuda")
output = model.generate(
    input_ids=inputs["input_ids"],
    attention_mask=inputs["attention_mask"],
    max_length=50,
    pad_token_id=tokenizer.pad_token_id,
    eos_token_id=tokenizer.eos_token_id,
)
print(tokenizer.decode(output[0], skip_special_tokens=True))